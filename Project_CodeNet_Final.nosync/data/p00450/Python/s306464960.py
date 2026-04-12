while 1:
    N = int(input())
    if N == 0:
        break
    st = []
    last = None
    for i in range(N):
        s = int(input())
        if last is None:
            last = [1, s]
            st.append(last)
            continue
        if last[1] == s:
            last[0] += 1
        else:
            if i % 2:
                P = st.pop()
                if st:
                    last = st[-1]
                    last[0] += P[0] + 1
                else:
                    last = [P[0]+1, s]
                    st.append(last)
            else:
                last = [1, s]
                st.append(last)
    ans = 0
    for s, c in st:
        if c == 0:
            ans += s
    print(ans)
