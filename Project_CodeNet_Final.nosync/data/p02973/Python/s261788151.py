import bisect

def main():
    n = int(input())
    buf = []
    a = [None] * n
    for i in range(n):
        a[i] = int(input())
    for i in reversed(a):
        index = bisect.bisect_right(buf, i)
        if index < len(buf) and buf[index] > i:
            buf[index] = i
        else:
            buf.append(i)
    print(len(buf))

if __name__ == "__main__":
    main()
