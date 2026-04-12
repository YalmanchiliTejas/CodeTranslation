n, k = map(int,input().split())
num = 0

for b in range(k+1,n+1):
    c = n%b
    num += (n//b)*(b-k) + max(0,c-k+1)
    if k == 0:
        num -= 1

print(num)
