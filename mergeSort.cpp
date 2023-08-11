//Date : 8/12/2023

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr,int left, int mid, int right){
    int leftSize=mid-left+1;
    int rightSize=right-mid;
    vector<int> leftArr(leftSize);
    vector<int> rightArr(rightSize);

    for(int i=0;i<leftSize;++i){
        leftArr[i]=arr[left+i];
    }
    for(int j=0;j<rightSize;++j){
        rightArr[j]=arr[mid+1+j];
    }

    int i=0, j=0, k=left;
    
    while(i<leftSize && j<rightSize){
        if(leftArr[i]<rightArr[j]){
            arr[k]=leftArr[i];
            ++i;
        }
        else{
            arr[k]=rightArr[j];
            ++j;
        }
        ++k;
    }
    while(i<leftSize){
        arr[k]=leftArr[i];
        ++i;
        ++k;
    }

    while(j<rightSize){
        arr[k]=rightArr[j];
        ++j;
        ++k;
    }    
}

void mergeSort(vector<int>& arr, int left, int right){
    if(left>=right)
        return;

    int mid=left+(right-left)/2;
    mergeSort(arr,left, mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right);
}

int main() {
    vector<int> arr = {4, 3, 2, 6, 4, 6, 7, 9, 12, 11, 15, 13};

    cout << "Original array : ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array   : ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}