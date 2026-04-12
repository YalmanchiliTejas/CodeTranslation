while True:
    amount , A, B, C, x = map(int, input().split())
    if amount == A == B == C == x == 0: break

    lille_frame = list(map(int, input().split()))
    frame_count = 0
    stop_count = 0

    while True:
        if x == lille_frame[stop_count]:
            stop_count += 1

        if stop_count == len(lille_frame):
            print(frame_count)
            break
        else:
            frame_count += 1

        if frame_count > 10000:
            print(-1)
            break

        x = (A * x + B) % C