def solve() :
    n = int(input())
    a = list(map(int, input().split()))
    a2 = [i ** 2 for i in a]

    print(((sum(a)**2 - sum(a2))//2)%(10**9+7))

if __name__ == "__main__" :
    solve()