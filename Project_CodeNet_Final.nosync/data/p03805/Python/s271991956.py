E_DICT = {}


def search_pass(v_idx, v_set, cnt):
    v_set2 = v_set.copy()
    v_set2.remove(v_idx)

    if len(v_set2) == 0:
        return cnt + 1

    e_tup = E_DICT[v_idx]

    for i in range(len(e_tup)):
        if e_tup[i] in v_set2:
            cnt = search_pass(e_tup[i], v_set2, cnt)

    return cnt


def main():
    n, m = map(int, input().split())
    v = {i+1 for i in range(n)}

    for i in range(m):
        a, b = map(int, input().split())

        if a in E_DICT:
            E_DICT[a].append(b)
        else:
            E_DICT[a] = [b]

        if b in E_DICT:
            E_DICT[b].append(a)
        else:
            E_DICT[b] = [a]

    if m == 0:
        comb = 0
    else:
        comb = search_pass(1, v, 0)

    print(comb)


if __name__ == '__main__':
    main()
