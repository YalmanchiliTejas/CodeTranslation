def Main():
    N = int(input())
    H = list(map(int, input().split()))
    ans = 0
    maxi = 0
    for h in H:
        if maxi <= h:
            ans += 1
        maxi = max(maxi, h)

    print(ans)
    
if __name__ == "__main__":
    Main()
