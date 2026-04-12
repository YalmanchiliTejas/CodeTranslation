def main():

    burgur = [0] * 51
    burgur[0] = 1
    pate = [0] * 51
    pate[0] = 1
    for i in range(50):
        burgur[i+1] = burgur[i] * 2 + 3
        pate[i+1] = pate[i] * 2 + 1
    
    N, X = map(int, input().split())

    X -= 1
    ans = 0
    for i in reversed(range(1, N+1)):
        if X == burgur[i] - 1:
            ans += pate[i]
            break
        elif X >= burgur[i-1] + 1:
            ans += pate[i-1] + 1
            X -= (burgur[i-1] + 2)
        else: 
            X -= 1
    if X == 0:
        ans += 1
    print(ans)
    

if __name__ == "__main__":
    main()