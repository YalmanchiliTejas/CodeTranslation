def feed_runrun(burger_dimension, appetite):
    if appetite == 0:
        return 0

    burger_size = 2 ** (burger_dimension + 2) - 3
    amount_of_p = 2 ** (burger_dimension + 1) - 1

    if appetite == burger_size:
        return amount_of_p
    if appetite < burger_size:
        return feed_runrun(burger_dimension - 1, appetite - 1)
    if appetite > burger_size:
        return amount_of_p + 1 \
               + feed_runrun(burger_dimension, appetite - burger_size - 1)


n, x = map(int, input().split())
print(feed_runrun(n, x))