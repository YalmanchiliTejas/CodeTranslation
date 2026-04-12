#n = int(input())
#n,k = map(int,input().split())
#x = list(map(int,input().split()))

x,y,z = map(int,input().split())

ans = 1
memo = y+2*z

while(memo<=x):
    ans += 1
    memo += y+z

print(ans-1)