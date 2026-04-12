from sys import stdin

def main():
    N = int(stdin.readline())
    H = list(map(int,stdin.readline().split()))
    answer = 1
    for i in range(1,len(H)):
        if H[i] >= max(H[:i]):
            answer += 1

    print(answer)

if __name__ == "__main__":
    main()
