# #!/usr/bin/env python3
# # -*- coding: utf-8 -*-


def main():
    N = int(input())
    H = list(map(int, input().split()))
    result = H[0]
    count = 0
    for h in H:
        if result <= h:
            count += 1
            result = h
    print(count)


if __name__ == "__main__":
    main()
