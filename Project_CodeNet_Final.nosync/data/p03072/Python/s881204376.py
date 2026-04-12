n=int(input())
h=list(map(int,input().split()))
hotel=0
for i in range(n):
    if h[i]==max(h[:i+1]):
        hotel+=1
print(hotel)