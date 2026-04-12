n=int(input())
h=list(map(int,input().split()))
a=1

for i in range(1,n):
    for j in range(i):
        if h[i]<h[j]:break
        elif j==i-1:
            a+=1

print(a)