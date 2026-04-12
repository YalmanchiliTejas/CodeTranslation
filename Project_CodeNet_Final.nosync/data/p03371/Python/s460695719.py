def solve():
    a,b,c,x,y = map(int,input().split())
    ans = 10**12
    for i in range(max(x,y+1)):
        cost = c*2*i
        dx = max(0,x-i)
        dy = max(0,y-i)
        cost+=dx*a
        cost+=dy*b
        ans = min(ans,cost)
    print(ans)
if __name__ == "__main__":
    solve()