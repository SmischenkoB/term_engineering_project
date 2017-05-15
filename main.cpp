#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
using namespace std;
void massive(int N, int* &p)
{   srand(time(NULL));
    p[0]=rand()%50;
    for(int i=1;i<N;i++){
        p[i]=p[i-1]+rand()%50+1;
    }
}
void binary_method(int N,int* p,int element){
    int start,end_of_array,mid;
    start =0;
    end_of_array=N-1;
    while (!(start >= end_of_array))
    {
        mid = start + (end_of_array - start) / 2;

        if (p[start] == element){
            cout<<start;
            return;}

        if (p[mid] == element)
        {
            if (mid == start + 1){
                cout<< mid;
                return;}
            else
                end_of_array = mid + 1;
        }

        else if (p[mid] > element)
            end_of_array = mid;
        else
            start = mid + 1;
    }
    cout<<"not found";
    return;
}


void odnorod_binary(int N,int* p,int element){
    int z=log(N)/log(2);
    int* table_j=new int[z+1];
    for(int j=0;j<(z+1);j++){
       table_j[j]= (pow(2,j)+N)/(pow(2,j+1));
    }
    int i= table_j[0];
    int j=1;
    while(true){
        if(element<p[i]){
            if(table_j[i]==0){cout<<"not found";return;}
            i-=table_j[j];
            j++;
        }
        if(element>p[i]){
            if(table_j[i]==0){cout<<"not found";return;}
            i+=table_j[j];
            j++;
        }
        if(element==p[i]){
            cout<<"pos = "<<i;
            return;
        }

    }
}



void simpe(int N,int *p,int  element){
    float time_work=clock();
    for(int i=0;i<N;i++){
        if(p[i]==element){
            cout<<endl<<i<<endl;
            break;
        }
    }
    cout<<endl<<clock()-time_work<<endl;
}


int main()
{   cout<<"quantity of elements"<<endl;
    int n,element;
    cin >>n;
    int *p=new int[n];
    massive(n,p);

    for(int i=0;i<n;i++){
        cout<<p[i]<<' ';
    }
     cin>>element;

   simpe(n,p,element);


    binary_method(n,p,element);

    odnorod_binary(n,p,element);
    return 0;
}
