def solve(x, y, z):

    tmp = x - z
    ans = tmp // (y + z)

    return ans

if __name__ == "__main__":
    x, y, z = [int(i) for i in input().split()]
    print(solve(x,y,z))