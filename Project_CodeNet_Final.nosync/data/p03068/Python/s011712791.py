def main():
    N = int(input())
    S = list(input())
    K = int(input())
    spec_s = S[K-1]
    ans = ""
    for i in range(len(S)):
        if S[i] != spec_s:
            S[i] = '*'
    for x in S:
        ans += x
    print(ans)
main()