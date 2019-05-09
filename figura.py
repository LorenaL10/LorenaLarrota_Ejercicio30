import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("temperatura.dat")

plt.figure(figsize=(15,5))
plt.imshow(data)
plt.xlabel("x")
plt.ylabel("U")

plt.plot(data[1;:]);

plt.xlabel("Indice X")
plt.ylabel("Temperatura")
plt.legend()
plt.savefig("plot.png", bbox_="tight")
