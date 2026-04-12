x,y,z = [int(i) for i in input().split()]
def sum(n):
    return y * n + z * (n+1)
ans = (x-z) // (y + z)
print(ans)