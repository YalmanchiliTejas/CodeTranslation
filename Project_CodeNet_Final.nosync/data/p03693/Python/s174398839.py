def main():
  num = list(map(int,input().split()))
  if (num[0]*100+num[1]*10+num[2])%4==0:
    print('YES')
  else:
    print('NO')
      
main()