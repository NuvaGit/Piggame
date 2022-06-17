#include <stdio.h>
int search(int arr[], int n, int x)
{
  int result;
  for(int i=0;i<n;i++){
    if(i == x){
      result = i;
    }
  }
  return result;
}
int main(void) {
  int x = 10;
  int arr[] = { 2, 3, 4, 10, 40 };
  int n = 5;
  int result1 = search(arr,5,10);
  printf("%d ",result1);
}
