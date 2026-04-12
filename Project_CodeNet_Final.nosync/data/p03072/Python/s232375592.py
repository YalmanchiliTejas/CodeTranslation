n = int(input())
h = list(map(int,input().split()))

yado = [0]*(n+1)

for i,n in enumerate(h):
    if max(h[:i+1]) == h[i]:
        yado[i]=1

print(sum(yado))