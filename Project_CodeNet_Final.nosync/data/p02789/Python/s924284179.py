# = int(input())
# = map(int, input().split())
# = list(map(int, input().split()))
# = list(input())
# = [tuple(map(int, input().split())) for _ in range(n)]

n, m = map(int, input().split())

if n == m:
    print('Yes')
else:
    print('No')
