def resolve():
    N = int(input())
    S = list(input())

    def get_next(p_prev, prev, prev_mark):
        anms = ["S", "W"]
        p_prev_idx = anms.index(p_prev)
        if prev_mark == "o":
            return anms[p_prev_idx] if prev== "S" else anms[(p_prev_idx+1)%2]
        else:
            return anms[(p_prev_idx+1)%2] if prev == "S" else anms[p_prev_idx]

    out = ["S", "S"]
    for i in range(2, N):
        out.append(get_next(out[i-2], out[i-1], S[i-1]))
    if get_next(out[-2], out[-1], S[-1]) == out[0] and get_next(out[-1], out[0], S[0]) == out[1]:
        print("".join(out))
        return

    out = ["S", "W"]
    for i in range(2, N):
        out.append(get_next(out[i-2], out[i-1], S[i-1]))
    if get_next(out[-2], out[-1], S[-1]) == out[0] and get_next(out[-1], out[0], S[0]) == out[1]:
        print("".join(out))
        return
    
    out = ["W", "S"]
    for i in range(2, N):
        out.append(get_next(out[i-2], out[i-1], S[i-1]))
    if get_next(out[-2], out[-1], S[-1]) == out[0] and get_next(out[-1], out[0], S[0]) == out[1]:
        print("".join(out))
        return
    
    out = ["W", "W"]
    for i in range(2, N):
        out.append(get_next(out[i-2], out[i-1], S[i-1]))
    if get_next(out[-2], out[-1], S[-1]) == out[0] and get_next(out[-1], out[0], S[0]) == out[1]:
        print("".join(out))
        return
    
    print(-1)

if __name__ == '__main__':
    resolve()