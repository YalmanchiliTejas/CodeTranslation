def main():
    N = int(input())
    M = [int(i) for i in input().split()]
    hm = 0
    count = 0
    for i in range(N):
        if hm <= M[i]:
            hm = M[i]
            count += 1
    print(count)
main()