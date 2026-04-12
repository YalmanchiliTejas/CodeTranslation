n= int(input())
h= list(map(int, input().split()))
cnt=1
a=h[0]
for i in range(1,n):
    if a<=h[i]:
        cnt+=1
        a=h[i]
print(cnt)