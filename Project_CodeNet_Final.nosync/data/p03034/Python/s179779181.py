n = int(input())
s = tuple(map(int,input().split()))

# a = A
# b = A-B
ans = 0
for b in range(1,(n-1)//2):
    point = 0
    count = 0
    for a in range((n-1-b), b, -b):
        if( a%b == 0)&( 2*a <= n-1):
            break
        count += 1
        point += s[b*count] + s[a]
        ans = max(point, ans)

print(ans)