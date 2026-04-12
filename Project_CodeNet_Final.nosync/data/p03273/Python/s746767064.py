import sys
input=sys.stdin.readline

def main():
    H, _ = map(int, input().split())
    G = []
    for i in range(H):
        G.append(input().strip())

    while True:
        find = False
        for i in G:
            if all(j == "." for j in i):
                G.remove(i)
                find = True
                break
        for i in range(len(G[0])):
            b = True
            for j in G:
                if j[i] != ".":
                    b = False
                    break
            if b:
                find = True
                for j,k in enumerate(G):
                    G[j] = k[:i] + k[i+1:]
                break
        if not find:
            for i in G:
                print(i)
            return

if __name__ == '__main__':
    main()
