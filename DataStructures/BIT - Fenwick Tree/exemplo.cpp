#include<bits/stdc++.h>
#define MAXSIZE 6
using namespace std;

int bits[MAXSIZE];
void update(int x, int val){
  x++;
  while(x<=MAXSIZE){
    bits[x]+=val;
    x += (x & -x);
  }
}

int query(int l, int r){
  l++;r++;
  int sum = 0;
  l--;
  while(l>0){
    sum -= bits[l];
    l -= (l & -l);
  }
  while(r>0){
    sum += bits[r];
    r -= (r & -r);
  }
  return sum;
}

int main(){
  int arr[] = {2, 0, 1, -4, 5, 6};
  for(int i=0;i<6;i++){
    update(i, arr[i]);
  }
  printf("Array: \n");
  printf("[2, 0, 1, -4, 5, 6]\n");
  printf("[|2, 0|, 1, -4, 5, 6]: %d\n", query(0,1) );
  printf("[|2, 0, 1, -4|, 5, 6]: %d\n", query(0,3) );
  printf("[2, 0, |1, -4, 5, 6|]: %d\n", query(2,5) );
  printf("[2, |0, 1, -4|, 5, 6]: %d\n", query(1,3) );
  printf("[|2, 0, 1, -4, 5, 6|]: %d\n", query(0,5) );
  printf("[2, 0, |1, -4|, 5, 6]: %d\n", query(2,3) );

}
