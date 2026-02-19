#include <GL/glut.h>
#include <stdio.h>

// Função para desenhar o conteúdo na tela
void display()
{
    // Limpa a tela com a cor de fundo definida
    glClear(GL_COLOR_BUFFER_BIT);

    // Inicia o desenho de um triângulo
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f); // Vermelho (Vértice 1)
    glVertex2f(-0.6f, -0.4f);

    glColor3f(0.0f, 1.0f, 0.0f); // Verde (Vértice 2)
    glVertex2f(0.6f, -0.4f);

    glColor3f(0.0f, 0.0f, 1.0f); // Azul (Vértice 3)
    glVertex2f(0.0f, 0.6f);
    glEnd();

    // Garante que os comandos sejam executados imediatamente
    glFlush();
}

int main(int argc, char **argv)
{
    // Inicializa o GLUT
    glutInit(&argc, argv);

    // Configura o modo de exibição (Buffer simples e cores RGB)
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Define o tamanho e a posição da janela
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);

    // Cria a janela com um título
    glutCreateWindow("Teste de Ambiente OpenGL/GLUT");

    // Define a cor de fundo (Cinza escuro)
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    // Registra a função de desenho
    glutDisplayFunc(display);

    printf("Janela aberta. Se voce ver um triangulo colorido, o ambiente esta OK!\n");

    // Entra no loop principal do GLUT
    glutMainLoop();

    return 0;
}