N=int(input())
H=list(map(int,input().split()))
result=0
H_max=H[0]
for i in range(len(H)):
  if H[i]>=H_max:
    result +=1
    H_max=H[i]
print(result)