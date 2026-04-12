n = int(input())
a = list(map(int, input().split()))
b = 10**9+7
sa = sum(a)
c=0
for i in a:
    c +=(i*i)%(2*b)

print(int((sa%(2*b)*sa%(2*b)-c%(2*b))/2)%b)