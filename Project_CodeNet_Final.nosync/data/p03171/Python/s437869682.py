import fileinput


def deque_score(item_list):
    player_a_scores = [0] * (len(item_list) * len(item_list))
    player_b_scores = [0] * (len(item_list) * len(item_list))

    for gap in range(len(item_list)):
        for li in range(len(item_list) - gap):

            if gap == 0:
                player_a_scores[li + len(item_list) * li] = item_list[li]
                player_b_scores[li + len(item_list) * li] = -item_list[li]
            else:
                ri = li + gap
                player_a_scores[li + len(item_list) * ri] = max(
                    item_list[li] + player_b_scores[(li + 1) + len(item_list) * ri],
                    item_list[ri] + player_b_scores[li + len(item_list) * (ri - 1)]
                )

                player_b_scores[li + len(item_list) * ri] = min(
                    player_a_scores[(li + 1) + len(item_list) * ri] - item_list[li],
                    player_a_scores[li + len(item_list) * (ri - 1)] - item_list[ri]
                )
    return player_a_scores[len(item_list) * (len(item_list) - 1)]


inp = fileinput.FileInput()
inp.readline()

item_list = [int(v) for v in inp.readline().split(" ")]
print(deque_score(item_list))