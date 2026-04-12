N =int(input())
H =[int(i) for i in input().split()]

maxhight=H[0]
answer=1
for i in range(1,N):
  if H[i]>=maxhight:
    answer=answer+1
    maxhight=H[i]
print(answer)