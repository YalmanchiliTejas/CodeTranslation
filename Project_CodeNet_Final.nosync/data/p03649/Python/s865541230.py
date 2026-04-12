def main():
    N,*A=map(int, open(0).read().split())
    ans = 0
    while any(a>=N for a in A):
        x = sum(a//N for a in A)
        A = [x-a//N+a%N for a in A]
        ans += x
    print(ans)

if __name__ == "__main__":
    main()