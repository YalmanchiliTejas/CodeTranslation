def e_sequence_sum():
    N, X, M = [int(i) for i in input().split()]

    appear = set([X])
    seq = [X]
    while True:
        seq.append(seq[-1]**2 % M)
        if seq[-1] in appear:
            break
        appear.add(seq[-1])
    loop_length = len(seq) - seq.index(seq[-1]) - 1
    seq.pop()
    first, loop = seq[:-loop_length], seq[-loop_length:]
    loop_count, reminder = divmod(N - len(first), loop_length)
    ans = sum(first) + sum(loop) * loop_count
    for i in range(reminder):
        ans += loop[i % reminder]
    return ans

print(e_sequence_sum())