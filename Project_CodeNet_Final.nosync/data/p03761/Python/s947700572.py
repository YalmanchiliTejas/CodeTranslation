n=int(input())
S=[0]*n
for i in range(n):
  S[i]=list(str(input()))

alfa='abcdefghijklmnopqrstuvwxyz'

ans=[]
for i in alfa:
  min_count=50
  for j in S:
    count = j.count(i)

    if count<min_count:
      min_count=count
  ans.append(i*min_count)
  print(i*min_count,end='')
#文字列が作れない場合空文字列を出力する
print()