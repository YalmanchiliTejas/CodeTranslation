from sys import stdin


def main():
    N = int(input())
    h_lst = [int(x) for x in stdin.readline().split()]
    lst = []
    count = 0
    for i in range(N):
        lst.append(h_lst[i])
        if h_lst[i] >= max(lst):
            count += 1
    print(count)


if __name__ == "__main__":
    main()
