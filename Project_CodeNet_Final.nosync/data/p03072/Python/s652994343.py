def q2():
    N = int(input())
    H = [int(i) for i in input().split()]

    ans = 0
    max_H = 0
    for i in range(N):
        if H[i] >= max_H:
            ans += 1
            max_H = H[i]

    return ans

if __name__ == '__main__':
    print(q2())
