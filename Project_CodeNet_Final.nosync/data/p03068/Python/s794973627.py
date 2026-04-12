if __name__=="__main__":
    N = int(input())
    S = input()
    K = int(input())

    match = S[K-1]
    S = list(S)
    for x in range(N):
        if S[x] != match:
            S[x]= '*'
    S = "".join(S)
    print(S)