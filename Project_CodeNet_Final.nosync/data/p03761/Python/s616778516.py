N = int(input())
START = ord('a')
END = ord('z')
LEN = abs(START - END) + 1

def count(s):
    arr = [0 for _ in range(LEN)]
    for c in list(s):
        arr[ord(c) - START] += 1
    return arr

def main():
    curr = [float('inf') for _ in range(LEN)]
    for _ in range(N):
        s = input()
        counted = count(s)
        curr = [min(t) for t in zip(curr, counted)]
    ans = ''.join([chr(i + START) * n for i, n in enumerate(curr)])
    print(ans)

if __name__ == '__main__':
    main()