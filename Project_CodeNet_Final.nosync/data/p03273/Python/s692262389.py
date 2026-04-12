import sys

input = sys.stdin.readline


def main():
    h, w = map(int, input().split())
    table = [[i == "#" for i in input().strip()] for _ in range(h)]
    table = list(filter(lambda x: sum(x), table))
    table = [[row[i] for row in table] for i in range(w)]
    table = list(filter(lambda x: sum(x), table))
    table = [[row[i] for row in table] for i in range(len(table[0]))]
    for row in table:
        print("".join(["#" if v else "." for v in row]))


if __name__ == "__main__":
    main()
