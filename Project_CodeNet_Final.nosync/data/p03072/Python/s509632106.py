def main():
  N=int(input())  #数値入力
  H=list(map(int, input().split()))  #リスト入力
  
  max_height=H[0]
  count=0
  
  for i in range(N):
    if H[i]>=max_height:
      count=count+1
      max_height=H[i]

  print(count)
    
main()