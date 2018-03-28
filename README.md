# TP_Multithreading
TP EPSI I4 - Thread

MEMBRES DE L'EQUIPE : 
- Romain ETIENNE ; 
- Adrien EXCOFFIER ; 
- Alex MEDINA ; 
- Amandine BUCAS

OBJECTIF DU PROJET : 
Améliorer les performances d'un protocole de messagerie. 
Pour cela, travail sur un client et un serveur de ce protocole.
Trouver une solution permettant l'affichage des messages reçus pendant que l'utilisateur est en train de lire un message.

SPECIFICATIONS : 
Tous les clients connectés sur le serveur ont accès à un salon de discussion commun.
Lorsque l'on envoie un message à un client, il est réceptionné par tous les autres clients.
Utilisation d'un fichier Makefile permettant la compilation des codes de serveur et de client.

PROTOCOLE DE COMMUNICATION : 
- Client vers Serveur 
  USER nom_d_utilisateur\n: indique au serveur le nom d'utilisateur choisi par le client. Le nom d'utilisateur ne doit pas contenir d'espace.
  MSG contenu_du_message\n: envoie un message sur le salon de discussion. Le message ne doit pas contenir de sauts de ligne
- Serveur vers Client
  MSG nom_d_utilisateur contenu_du_message: contient un message envoyé par un autre utilisateur
