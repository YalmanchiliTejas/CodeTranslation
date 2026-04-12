N = int(input())
H = list(map(int, input().split())) 
 
k= 1
for i in range(1,N):
    if sorted(H[0:i])[-1]<=H[i]:
        k=k+1
    else:
        k=k
print(k)