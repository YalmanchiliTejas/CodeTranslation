def read_values():
    return map(int, input().split())


def read_list():
    return list(read_values())


def main():
    H, W = read_values()
    F = [input() for _ in range(H)]

    T = [False] * W
    for f in F:
        if f.count("#") == 0:
            continue
        
        for w, s in enumerate(f):
            if s == "#":
                T[w] = True

    for f in F:
        if f.count("#") == 0:
            continue
        print("".join([s for i, s in enumerate(f) if T[i]]))


if __name__ == "__main__":
    main()
