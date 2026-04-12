def main():
    n = int(input())
    S = sorted([list(input()) for i in range(n)], key = lambda x : len(x))
    common = [[False for i in range(len(X))] for X in S]

    ref = S[0]
    ans = list()
    for i in range(len(ref)):

        is_common = True
        for j in range(1, len(S)):
            
            find = False
            for k in range(len(S[j])):
                if S[j][k] == ref[i] and common[j][k] == False:
                    common[j][k] = True
                    find = True
                    break

            is_common &= find

        if is_common:
            ans.append(ref[i])

    print("".join(sorted(ans)))

if __name__ == "__main__":
    main()