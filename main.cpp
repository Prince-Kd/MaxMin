#include <iostream>
#include <stdlib.h>

using namespace std;

void MaxMin(int arr[],int low,int high, int *max, int *min)
{
    int mid,maxA,maxB,minA,minB;
    if(high-low == 1)
    {
        if(arr[low] > arr[high])
        {
            *max = arr[low];
            *min = arr[high];
        } else
        {
            *max = arr[high];
            *min = arr[low];
        }
    }
    else if(low == high)
    {
        *min = *max = arr[low];
    }
    else if(low < high)
    {
        mid=(low + high)/2;
        MaxMin(arr,low,mid,&maxA,&minA);
        MaxMin(arr,mid+1,high,&maxB,&minB);
        if(maxA > maxB)
            *max = maxA;
        else
            *max = maxB;
        if(minA < minB)
            *min = minA;
        else
            *min = minB;
    }
}

int main()
{
    int Arr[50000],Num,i;
    int aMax=0,aMin=0;
    cout<<"Enter the size of the array"<<endl;
    cin>>Num;
    cout<<"Enter the members of the array:"<<endl;
    for(i = 0; i < Num; i++)
        cin>>Arr[i];
    MaxMin(Arr, 0, Num-1, &aMax, &aMin);
    cout<<"Maximum Element = "<<aMax<<endl;
    cout<<"Minimum Element = "<<aMin;

    return 0;
}
