def solve(n):
    a = [int(input()) for i in range(n)]
    print((sum(a)-max(a)-min(a))//(n-2))


while(True):
    n = int(input())
    if(n == 0):
        quit()
    solve(n)

