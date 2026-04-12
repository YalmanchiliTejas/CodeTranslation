def solve():
    N=int(input())
    print((N//15)*(800*15-200)+(N%15)*800)

if __name__ == "__main__":
    solve()