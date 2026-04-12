n=int(raw_input())
a=map(int,raw_input().split())

for i in range((n+1)/2):
    print a[n-2*i-1],
for i in range(n/2):
    print a[i*2+n%2],
print ''