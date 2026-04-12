n = int( input() )
h = list( map( int, input().split() ) )

max_high = 0
ans = 0
for i in range(n):
    if max_high <= h[i]:
        ans += 1
        max_high = h[i]

print(ans)