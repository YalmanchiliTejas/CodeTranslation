
n = int(input())
a = list(map(int,input().split()))


b = [None]*n
b[0] = a[0]

for i in range(n-1):
    b[i+1] = (b[i] + a[i+1]) % 1000000007;

con = 0;

for v in range(1,n):
    x = (a[-v] * b[-v-1]) % 1000000007;
    con = (con + x) % 1000000007;

print(con)