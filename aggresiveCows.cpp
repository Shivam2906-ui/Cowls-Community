#include<iostream>
using namespace std;

int sort(int arr[],int n){

    for(int i=0;i<n;i++){
        int minIndex=arr[i];

        for(int j=i+1;j<n;j++){
            if(arr[j]<minIndex){
                minIndex=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[minIndex];
        arr[minIndex]=temp;
    }
}

bool isPossible(int arr[],int n,int k,int mid){

    int cowCount=1;
    int lastPos=arr[0];

    for(int i=0;i<n;i++){
        if(arr[i]-lastPos>=mid){
            cowCount++;
            if(cowCount==k){
                return true;
            }
            lastPos=arr[i];
        }
    }
    return false;
}

int aggresiveCows(int arr[],int n,int k){

    int s=0;
    int maxi=-1;
    for(int i=0;i<n;i++){
        maxi=max(maxi,arr[i]);
    }
    int e=maxi;
    int mid=s+(e-s)/2;
    
    int ans=-1;
    while(s<=e){
        if(isPossible(arr,n,k,mid)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

int main(){
    
    int arr[5]={1,4,2,5,9};// This array is not sorted so,that after sorting binary search or search space concept is applicable that because i am making function sort in this code
    int k=2;

    cout<<"Answer is : "<<aggresiveCows(arr,5,k)<<endl;


    return 0;

}