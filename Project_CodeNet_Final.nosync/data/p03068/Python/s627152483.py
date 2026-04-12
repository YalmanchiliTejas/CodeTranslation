###
#main
if __name__ == "__main__":
    N = int(input())
    S = input()
    K = int(input())
    target = S[K-1]
    result = ""
    for i in range(len(S)):
        if S[i] != target:
            result += "*"
        else:
            result += S[i]
    print(result)