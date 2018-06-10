//Todas operações em O(logn)
//0 indexado
//INTERVALSIZE -> é o tamanho do intervalo
int bits[INTERVALSIZE];
void update(int x, int val){
  x++;
  while(x<=INTERVALSIZE){
    bits[x]+=val;
    x += (x & -x);
  }
}

//arr[l] + arr[l+1] ... + arr[r]
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
