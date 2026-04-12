def feed_runrun(answer, burger_dimension, appetite):
    if appetite == 0:
        return answer

    burger_size = 2 ** (burger_dimension + 2) - 3
    # 食べきれない
    if appetite < burger_size:
        return feed_runrun(answer, burger_dimension - 1, appetite - 1)
    # 食べきれる
    amount_of_p = 2 ** (burger_dimension + 1) - 1
    if appetite >= burger_size + 1:
        return feed_runrun(answer + amount_of_p + 1, burger_dimension, appetite - burger_size - 1)
    return feed_runrun(answer + amount_of_p, burger_dimension, appetite - burger_size)


n, x = map(int, input().split())
print(feed_runrun(0, n, x))