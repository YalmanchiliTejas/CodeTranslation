def slove(n, m):

    if n == m :
        return "Yes"
    else:
        return "No"

if __name__ == "__main__":

    n, m = [int(i) for i in input().split()]

    ans = slove(n, m)

    print(ans)